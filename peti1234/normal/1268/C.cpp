#include <bits/stdc++.h>

using namespace std;
long long lsb(long long a) {
    return ((a) & -(a));
}
long long n, sum, db, mini=INT_MAX, csere, res;
long long ft[200001], ossz[200001], t[200001];
long long ask(long long a, int b) {
    long long ans=0;
    if (!b) {
        while(a>0) ans+=ft[a], a-=lsb(a);
        return ans;
    }
    while(a>0) ans+=ossz[a], a-=lsb(a);
    return ans;
}
void upd(long long a, int b) {
    if (!b) while (a<=n) ft[a]++, a+=lsb(a);
    else while(a<=n) ossz[a]+=b, a+=lsb(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        t[x]=i;
    }
    for (long long i=1; i<=n; i++) {
        long long x=t[i];
        csere+=i-1-ask(x, 0);
        upd(x, 0);
        int low=0, high=n+1;
        while (high-low>1) {
            int mid=(low+high)/2;
            if (ask(mid, 0)>=(i+1)/2) high=mid;
            else low=mid;
        }
        low++;
        upd(x, x);
        res=csere;
        db=ask(low, 0), sum=ask(low, 1);
        res+=low*db-db*(db-1)/2-sum;
        db=-db, sum=-sum;
        db+=ask(n, 0), sum+=ask(n, 1);
        res+=sum-low*db-db*(db+1)/2;
        cout << res << " ";
    }
    return 0;
}
/*
5
1 4 2 5 3
*/