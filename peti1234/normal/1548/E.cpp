#include <bits/stdc++.h>

using namespace std;
const int c=200005, k=20;
int n, m, sum, f[c], t[c][2], ert[c][2], lg[c], po[k], maxi[c][k][2];
long long ans=0;
vector<int> sz;
vector<pair<int, pair<int, int> > > p;
int calc(int a, int b, int id) {
    if (b<a) {
        return c;
    }
    int s=lg[b-a+1];
    return sum+1-max(maxi[a][s][id], maxi[b+1-po[s]][s][id]);
}
void pb(int a, int b, int c) {
    //cout << "uj " << a << " " << b << " " << c << "\n";
    p.push_back({a, {b, c}});
}
int lsb(int a) {
    return (a & (-a));
}
void add(int a, int b) {
    while (a<c) {
        f[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=f[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> sum;
    t[0][0]=n, t[0][1]=m;
    for (int i=2; i<c; i++) {
        lg[i]=lg[i/2]+1;
    }
    for (int i=0; i<k; i++) {
        po[i]=(1<<i);
    }
    for (int id=0; id<2; id++) {
        int s=t[0][id];
        for (int i=1; i<=s; i++) {
            cin >> t[i][id];
            maxi[i][0][id]=t[i][id];
        }

        for (int j=1; j<k; j++) {
            for (int i=1; i+po[j]<=s+1; i++) {
                maxi[i][j][id]=max(maxi[i][j-1][id], maxi[i+po[j-1]][j-1][id]);
            }
        }

        for (int i=1; i<=s; i++) {
            ert[i][id]=1;
            while (sz.size()>0 && t[i][id]<t[sz.back()][id]) {
                sz.pop_back();
            }
            if (sz.size()>0) {
                ert[i][id]=max(ert[i][id], calc(sz.back()+1, i-1, id));
            }
            sz.push_back(i);
        }
        sz.clear();
        for (int i=s; i>=1; i--) {
            while (sz.size()>0 && t[i][id]<=t[sz.back()][id]) {
                sz.pop_back();
            }
            if (sz.size()>0) {
                ert[i][id]=max(ert[i][id], calc(i+1, sz.back()-1, id));
            }
            sz.push_back(i);
        }
        sz.clear();


        for (int i=1; i<=s; i++) {
            int a=sum-t[i][id], b=ert[i][id];
            if (b<=a) {
                if (id==0) {
                    pb(b, 0, t[i][0]), pb(a+1, 0, -t[i][0]);
                } else {
                    pb(t[i][id], 1, i);
                }
            }
        }
    }

    sort(p.begin(), p.end());
    for (auto x:p) {
        int val=x.first, q=x.second.first, id=x.second.second;
        if (q==0) {
            add(abs(id), (id>0 ? 1 : -1));
        } else {
            int a=sum-t[id][1], b=ert[id][1];
            ans+=ask(a)-ask(b-1);
        }
    }

    cout << ans << "\n";
    return 0;
}
/*
3 4 12
9 8 5
10 6 7 2
*/