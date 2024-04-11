#include <bits/stdc++.h>

using namespace std;
long long n;
priority_queue<pair<long long, pair<long long, long long>>>q;
long long x=0, y=0;
int main()
{
    cin >> n;
    q.push({n,{0, 0}});
    while(q.size()>0) {
        long long e=q.top().first;
        long long d=q.top().second.first;
        long long l=q.top().second.second;
        long long a=0, b=100001;
        while(b-a>1) {
            long long c=(a+b)/2;
            if (c*c*c<=e) {
                a=c;
            } else {
                b=c;
            }
        }
        q.pop();
        if (e!=0) {
        q.push({e-a*a*a, {d+1, l+a*a*a}});
        if (a!=1) {
            long long p=a*a*a-1;
            q.push({p-(a-1)*(a-1)*(a-1), {d+1, l+(a-1)*(a-1)*(a-1)}});
        }
        } else {
            if (d>x || (d==x && l>y)) {
                x=d;
                y=l;
            }
        }
    }
    cout << x << " " << y << endl;
    return 0;
}