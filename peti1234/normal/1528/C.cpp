#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, maxi;
int be[c], ki[c], cnt, db;
long long ert[c];
vector<int> sz1[c], sz2[c];
int fel1[c], fel2[c];
bool baj=0;
int lsb(int a) {
    return (a & (-a));
}
void add(int a, int pl) {
    if (a<=0) {
        return;
    }
    while (a<=n) {
        ert[a]+=pl;
        a+=lsb(a);
    }
}
int ask(int a) {
    long long ans=0;
    while (a>0) {
        ans+=ert[a];
        a-=lsb(a);
    }
    return ans;
}
void add2(int a, int pl) {
    if ((a<=0 || a>n) && !baj) {
        baj=1;

        cout << "nagyonnagybaj\n";
        for (int i=1; i<=n; i++) {
            cout << fel1[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            cout << fel2[i] << " ";
        }
        cout << "\n";

        return;

    }
    if (pl>0) {
        db++;
    } else {
        db--;
    }
    add(be[a], pl);
    add(ki[a]+1, -pl);
}

void dfs1(int a) {
    int spec=ask(be[a]);
    //cout << "dfs1 " << a << " " << spec << "\n";
    if (spec) {
        add2(spec, -spec);
    }
    add2(a, a);
    maxi=max(maxi, db);
    for (int x:sz1[a]) {
        dfs1(x);
    }
    add2(a, -a);
    if (spec) {
        add2(spec, spec);
    }
}
void dfs2(int a) {
    cnt++;
    be[a]=cnt;
    for (int x:sz2[a]) {
        dfs2(x);
    }
    ki[a]=cnt;
}
int vel(int a) {
    int x=rand()%(a-1)+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n;
        //n=5000;

        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            sz1[x].push_back(i);
        }
        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            sz2[x].push_back(i);
        }

/*
        for (int i=2; i<=n; i++) {
            fel1[i]=vel(i);
            sz1[fel1[i]].push_back(i);
        }
        for (int i=2; i<=n; i++) {
            fel2[i]=vel(i);
            sz2[fel2[i]].push_back(i);
        }
*/
        dfs2(1);
        for (int i=1; i<=n; i++) {
            //cout << be[i] << " " << ki[i] << "\n";
        }
        dfs1(1);
        //cout << "valasz: ";
        cout << maxi << "\n";

        cnt=0, db=0, maxi=0;
        for (int i=1; i<=n; i++) {
            sz1[i].clear(), sz2[i].clear();
            be[i]=0, ki[i]=0, ert[i]=0;
        }
        if (baj) {
            return 0;
        }
    }
    return 0;
}
/*
1
4
1 2 3
1 2 1
*/
/*
0 1 2 2 3
0 1 2 1 1
*/
/*
1
10
0 1 2 3 2 5 5 4 4 6
0 1 1 2 1 3 5 4 7 1
*/