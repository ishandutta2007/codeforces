
#include <bits/stdc++.h>

using namespace std;
const int c=64, c2=1002, mod=998244353;
typedef vector<int> sor;
typedef vector<sor> mat;
void init(mat &a) {
    a.resize(c);
    for (int i=0; i<c; i++) {
        a[i].resize(c);
        for (int j=0; j<c; j++) {
            a[i][j]=0;
        }
    }
}
int add(int a, int b) {
    return (a+b)%mod;
}
int add2(int &a, int b) {
    a=add(a, b);
}
mat matadd(mat a, mat b) {
    mat ans;
    init(ans);
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            ans[i][j]=add(a[i][j], b[i][j]);
        }
    }
}
int mul(int a, int b) {
    return 1ll*a*b%mod;
}
int mex(sor a) {
    //cout << "mex " << a.size() << "\n";
    a.push_back(100);
    sort(a.begin(), a.end());
    if (a[0]) {
        return 0;
    }
    for (int i=1; i<a.size(); i++) {
        if (a[i]>a[i-1]+1) {
            return a[i-1]+1;
        }
    }
}

sor mul1(mat a, sor b)
{
	vector<int> ans(c);
	for (int i=0; i<c; i++) {
		for (int j = 0; j<c; j++) {
			add2(ans[i], mul(a[i][j], b[j]));
		}
	}
	return ans;
}
mat mul2(mat a, mat b) {
    mat ans;
    init(ans);
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            for (int k=0; k<c; k++) {
                add2(ans[i][k], mul(a[i][j], b[j][k]));
            }
        }
    }
    return ans;
}

int n, m, hossz[c2], f[3][3], regi[4], uj[4];
vector<pair<int, int> > sz[c2];
mat po[31], spec[3], alap;
sor gyorsures(sor kezd, int hatv) {
    for (int ert=0; hatv>0; ert++) {
        if (hatv%2) {
            kezd=mul1(po[ert], kezd);
        }
        hatv/=2;
    }
    return kezd;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> hossz[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({b, --c});
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> f[i][j];
        }
    }
    init(alap);
    for (int ii=0; ii<3; ii++) {
        init(spec[ii]);
        for (int i=0; i<c; i++) {
            sor pos;
            int i3=i;
            for (int j=0; j<3; j++) {
                if (f[ii][j]) {
                    pos.push_back(i3%4);
                }
                i3/=4;
            }
            int ert=mex(pos);
            int kov=i*4%c+ert;
            //cout << i << " " << kov << "\n";
            spec[ii][kov][i]++;
            alap[kov][i]++;
        }
        //return 0;
    }
    po[0]=alap;
    for (int i=1; i<=30; i++) {
        po[i]=mul2(po[i-1], po[i-1]);
    }
    regi[0]=1;
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
        sor most(64);
        most[63]=1;
        int ut=0;
        for (auto fix:sz[i]) {
            int fi=fix.first, cl=fix.second;
            most=gyorsures(most, fi-ut-1);
            most=mul1(spec[cl], most);
            ut=fi;
        }
        //cout << "kezd " << most[63] << "\n";
        most=gyorsures(most, hossz[i]-ut);

        for (int i=0; i<c; i++) {
            //cout << "ertek " << i << " " << most[i] << "\n";
            for (int j=0; j<4; j++) {
                int kov=(i%4)^j;

                uj[kov]=add(uj[kov], mul(regi[j], most[i]));
            }
        }


        for (int i=0; i<4; i++) {
            regi[i]=uj[i];
            uj[i]=0;
        }
    }
    cout << regi[0] << "\n";
    return 0;
}