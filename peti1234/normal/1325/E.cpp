#include <bits/stdc++.h>

using namespace std;
const int c=100002, q=1000002;
int n, cnt=2, pr[c], mini, szint[c];
bool v[c], h[q];
vector<int> sz[c], oszt[q];
queue<pair<int, int> > cs;
int main()
{
    cin >> n, pr[1]=1, mini=n+1;
    for (int i=2; i<q; i++) if (!h[i]) {
        pr[cnt]=i, cnt++;
        for (int j=i; j<q; j+=i) h[j]=1, oszt[j].push_back(cnt-1);
    }
    for (int i=1; i<=n; i++) {
        long long x, y, p=1, q=1;
        cin >> x, y=x;
        for (int i=0; i<oszt[x].size(); i++) {
            long long a=pr[oszt[x][i]], b=oszt[x][i];
            while(y%(a*a)==0) y/=a*a;
            if (y%a==0) {
                if (p==1) p=b;
                else q=b;
            }
        }
        //cout << p << " " << q << endl;
        if (p==q) mini=1;
        sz[p].push_back(q), sz[q].push_back(p);
    }
    for (int i=1; pr[i]<=1000; i++) {
        for (int i=1; i<=cnt; i++) v[i]=0, szint[i]=0;
        cs.push({i, 0});
        while(cs.size()>0) {
            int id=cs.front().first, dist=cs.front().second;
            cs.pop();
            if (v[id]) mini=min(mini, szint[id]+dist);
            else {
                v[id]=1, szint[id]=dist;
                for (int i=0; i<sz[id].size(); i++) {
                    int x=sz[id][i];
                    if (!v[x]) cs.push({x, dist+1});
                }
            }
        }
    }
    if (mini==n+1) mini=-1;
    cout << mini << "\n";
    return 0;
}