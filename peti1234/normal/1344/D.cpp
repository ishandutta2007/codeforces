#include <bits/stdc++.h>

using namespace std;
long long ke=-1e10, so=4e18, f=0;
long long n, k, t[100002], m[100002], db;
priority_queue<pair<long long, long long> > q;
long long opt(long long a, long long b) {
    long long c=(t[a]+b)/3;
    if (c<=0) return 0;
    c=sqrt(c), c=max(f, c-1);
    if (3*c*c+3*c+1<=t[a]+b) c++;
    c=min(t[a], c);
    return c;

}
void add(long long i) {if (t[i]!=m[i]) q.push({t[i]-3*m[i]*m[i]-3*m[i], i});}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (long long i=1; i<=n; i++) cin >> t[i];
	while(so-ke>1) {
        long long mi=(so+ke)/2, db=0;
        for (long long i=1; i<=n; i++) m[i]=opt(i, mi), db+=m[i];
        if (db<=k) ke=mi;
        else so=mi;
	}
	db=0;
	for (int i=1; i<=n; i++) m[i]=opt(i, ke), db+=m[i];
	for (long long i=1; i<=n; i++) add(i);
	while(db<k) {
        long long id=q.top().second;
        db++, q.pop(), m[id]++, add(id);
	}
	for (long long i=1; i<=n; i++) cout << m[i] << " ";
    return 0;
}