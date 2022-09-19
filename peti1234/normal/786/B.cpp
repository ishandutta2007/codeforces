#include <bits/stdc++.h>

using namespace std;
const int c=131072;
int kezd[3*c], veg[3*c], n, w, s;
long long dist[3*c];
bool v[3*c];
priority_queue<pair<long long, int> > q;
vector<pair<int, int> >sz[3*c];
void add(int a, int b, int c) {
    //cout << a << " " << b << " " << c << endl;
    sz[a].push_back({b, c});
}
void le(int p, int k, int v, int a, int x) {
    int st=kezd[p], fi=veg[p];
    if (st>v || fi<k) return;
    if (k<=st && fi<=v) add(a, p, x);
    else le(2*p, k, v, a, x), le(2*p+1, k, v, a, x);
}
void fel(int p, int k, int v, int a, int x) {
    if (p>=3*c) p-=2*c;
    int st=kezd[p], fi=veg[p];
    if (st>v || fi<k) return;
    if (k<=st && fi<=v) add(p, a, x);
    else fel(2*(p-c), k, v, a, x), fel(2*(p-c)+1, k, v, a, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> w >> s;
    for (int i=c; i<2*c; i++) kezd[i]=i-c+1, veg[i]=i-c+1;
    for (int i=c-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1], add(i, 2*i, 0), add(i, 2*i+1, 0);
    for (int i=2*c+c/2; i<3*c; i++) {
        int b=2*(i-2*c), j=b+1;
        kezd[i]=kezd[b], veg[i]=veg[j], add(b, i, 0), add(j, i, 0);
    }
    for (int i=2*c+c/2-1; i>2*c; i--) {
        int b=2*(i-c), j=b+1;
        kezd[i]=kezd[b], veg[i]=veg[j], add(b, i, 0), add(j, i, 0);
    }
    for (int i=1; i<=w; i++) {
        int t;
        cin >> t;
        if (t==1) {
            int a, b, x;
            cin >> a >> b >> x;
            add(a+c-1, b+c-1, x);
        } else {
            int a, k, v, x;
            cin >> a >> k >> v >> x;
            if (t==2) le(1, k, v, a+c-1, x);
            else fel(2*c+1, k, v, a+c-1, x);
        }
    }
    for (int i=c; i<2*c; i++) dist[i]=-1;
    q.push({0, s+c-1});
    while(q.size()) {
        long long tav=q.top().first, id=q.top().second;
        //cout << id << " " << -tav << endl;
        q.pop();
        if (!v[id]) {
            v[id]=true, dist[id]=-tav;
            for (int i=0; i<sz[id].size(); i++) {
                int fi=sz[id][i].first, se=sz[id][i].second;
                if (!v[fi]) q.push({tav-se, fi});
            }
        }
    }
    for (int i=c; i<c+n; i++) cout << dist[i] << "\n";
    return 0;
}