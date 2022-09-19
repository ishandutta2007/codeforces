#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, rf[c], hol[c], cent, cnt;
int si[c], db2[2*c], maxi, pos, ans[c];
priority_queue<int, vector<int>, greater<int> >q;
long long sum;
vector<int> sz[c], s[c], csop[c];
bool v[c], v2[c], h[c];
void dfs(int a) {
    v[a]=true;
    rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        long long y=s[a][i];
        if (!v[x]) {
            dfs(x);
            sum+=y*min(rf[x], n-rf[x]);
            rf[a]+=rf[x];
        }
    }
    if (!cent && 2*rf[a]>=n) {
        cent=a;
    }
}
void dfs2(int a) {
    v2[a]=true;
    csop[cnt].push_back(a), hol[a]=cnt;
    for (int x:sz[a]) {
        if (!v2[x]) {
            dfs2(x);
        }
    }
}
void cl(int a) {
    db2[si[a]]--;
    si[a]--;
    if (si[a]<0) {
        //cout << "Nagyon nagy baj\n";
    }
    db2[si[a]]++;
    if (!db2[maxi]) {
        maxi--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n==1) {
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //cin >> a >> b;
        //c=0;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back(c), s[b].push_back(c);
    }
    dfs(1);
    cout << 2*sum << "\n";
    csop[1].push_back(cent);
    v2[cent]=1, hol[cent]=1;
    cnt=1;
    for (int x:sz[cent]) {
        cnt++;
        dfs2(x);
    }
    for (int i=1; i<=cnt; i++) {
        si[i]=2*(csop[i].size());
        db2[si[i]]++;
        sort(csop[i].rbegin(), csop[i].rend());
        q.push(csop[i].back());
        csop[i].pop_back();
        maxi=max(maxi, si[i]);
    }
    si[1]=0, db2[2]--;
    while (maxi<n-pos) {
        pos++;
        int ert=q.top(), spec=0;
        if (pos==736) {
            //cout << "baj_" << ert << "\n";
        }
        if (pos!=cent && hol[pos]==hol[ert]) {
            if (pos==736) {
                //cout << "valt_" << ert << "_" << q.top() << "\n";
            }
            spec=ert;
            q.pop();
            ert=q.top();
        }
        q.pop();
        if (spec) {
            q.push(spec);
        }
        ans[pos]=ert;
        //cout << "par " << pos << " " << ert << "\n";
        h[ert]=1;
        int p=hol[ert];
        cl(hol[pos]), cl(p);
        if (csop[p].size()>0) {
            q.push(csop[p].back());
            csop[p].pop_back();
        }
    }
    if (n==1000) {
        //cout << "sima " << pos << "\n";
    }
    int spec=0;
    for (int i=1; i<=cnt; i++) {
        if (si[i]==maxi) {
            spec=i;
        }
    }
    //cout << "vege " << maxi << " " << spec << "\n";
    vector<int> mcs, mas;
    for (int i=1; i<=n; i++) {
        if (!h[i]) {
            if (hol[i]==spec) {
                mcs.push_back(i);
            } else {
                mas.push_back(i);
            }
        }
    }
    //cout << mcs.size() << " " << mas.size() << "\n";
    //return 0;
    int pos1=0, pos2=0;
    for (int i=pos+1; i<=n; i++) {
        if (hol[i]==spec) {
            ans[i]=mas[pos2];
            pos2++;
        } else {
            ans[i]=mcs[pos1];
            pos1++;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
/*
7
1 2 1 3 1 4
1 5 1 6 1 7
*/