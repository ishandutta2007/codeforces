#include <bits/stdc++.h>

using namespace std;
long long n;
long long x[1001];
long long y[1001];
long long db;
long long sum=0;
bool t[1001][1001];
vector<pair<long long, long long> > e;
vector<pair<pair<long long, long long>, long long> > q;
long long gcd(long long a, long long b) {
    if (a>b) {
        swap(a, b);
    }
    if (a==0) {
        return b;
    }
    return gcd(a, b%a);
}
int main()
{
    cin >> n;
    for (long long i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (long long i=1; i<=n; i++) {
        for (long long j=i+1; j<=n; j++) {
            if (!t[i][j]) {
                t[i][j]=true;
                long long a=x[i]-x[j];
                long long b=y[i]-y[j];
                if (a<0) {
                    a*=-1;
                    b*=-1;
                }
                bool w=(b<0);
                b=abs(b);
                long long p=gcd(a, b);
                a/=p;
                b/=p;
                if (w) {
                    b*=-1;
                }
                if (a==0) {
                    b=abs(b);
                }
                q.push_back({{a, b}, j});
            }
        }
        sort(q.begin(), q.end());
        for (long long i=0; i<q.size(); i++) {
            long long a=i+1;
            while(a<q.size() && q[i].first.first==q[a].first.first && q[i].first.second==q[a].first.second) {
                long long c=q[i].second;
                long long b=q[a].second;
                t[c][b]=true;
                t[b][c]=true;
                a++;
            }
            long long fi=q[i].first.first;
            long long se=q[i].first.second;
            if (i==0 || fi!=q[i-1].first.first || se!=q[i-1].first.second) {
                e.push_back({fi, se});
                //cout << fi << " " << se << endl;
            }
        }
        q.clear();
    }
    sort(e.begin(), e.end());
    db=e.size();
    //cout << db << endl;
    sum+=db*(db-1)/2;
    for (long long i=0; i<e.size(); i++) {
        long long fi=e[i].first;
        long long se=e[i].second;
        long long a=i+1;
        while(a<db && e[a].first==fi && e[a].second==se) {
            a++;
        }
        //cout << (a-i) << endl;
        sum-=(a-i)*(a-i-1)/2;
        i=a-1;
    }
    cout << sum << endl;
    return 0;
}
/*
9
0 0 0 1 0 2
1 0 1 1 1 2
2 0 2 1 2 2
*/