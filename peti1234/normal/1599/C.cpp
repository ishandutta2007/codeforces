#include <bits/stdc++.h>

using namespace std;
long long n, lo, hi, mid;
long double prob;
int main()
{
    cin >> n >> prob;
    lo=-1, hi=n;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        long double p=mid, s=0;
        s+=p*(p-1)*(p-2);
        s+=3*p*(p-1)*(n-p);
        s+=3*p*(n-p)*(n-p-1)*0.5;
        s/=n*(n-1)*(n-2);
        //cout << "proba " << mid << " " << s << "\n";
        if (s+(1e-9)>prob) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    cout << hi << "\n";
    return 0;
}