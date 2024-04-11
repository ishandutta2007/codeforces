#include <bits/stdc++.h>

using namespace std;
const int c=525, k=300002;
int n, adb[k], db[k], el, comp, spc;
vector<int> sz[k];
queue<int> q;
bool inf[k], v[k], kor;
int t(int a, int b) {
    return a*c+b;
}
void add(int a, int b) {
    inf[a]=1;
    for (int x:sz[a]) {
        db[x]++;
        adb[x]+=b;
        if (db[x]>1) q.push(x);
    }
}
void dfs(int a) {
    v[a]=true;
    int db=0;
    for (int x:sz[a]) {
        if (inf[x]) {
            if (!v[x]) dfs(x);
            else db++;
        }
    }
    if (db>1) kor=true;
}
int main()
{
    cin >> n;
    for (int i=1; i<c; i++) {
        for (int j=1; j<c; j++) {
            int x=t(i, j);
            sz[x].push_back(t(i-1, j));
            sz[x].push_back(t(i+1, j));
            if (i%2==0) sz[x].push_back(t(i+1, j-1));
            else sz[x].push_back(t(i-1, j+1));
        }
    }
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        a+=10, b+=10;
        add(t(a, b), 1);
    }
    for (int i=1; i<k; i++) {
        for (int j:sz[i]) {
            if (inf[i]!=inf[j]) el++;
        }
    }
    el/=2;
    while(q.size()>0) {
        int id=q.front();
        q.pop();
        if (!inf[id]) {
            add(id, 0);
        }
    }
    for (int i=0; i<k; i++) {
        if (!v[i] && inf[i]) {
            dfs(i);
            comp++;
        }
    }
    for (int i=0; i<k; i++) {
        if (adb[i]==3) {
            int sum=0;
            for (int j=0; j<3; j++) {
                int x=sz[i][j];
                sum+=adb[x];
                for (int k=0; k<3; k++) {
                    int y=sz[x][k];
                    sum+=inf[y];
                }
            }
            if (sum==3) spc++;
        }
    }
    if (kor) cout << "SICK\n";
    else cout << "RECOVERED\n" << el-2*(comp+spc) << "\n";
    return 0;
}