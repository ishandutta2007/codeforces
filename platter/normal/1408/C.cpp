#include <bits/stdc++.h>
using namespace std;

int n,l;
int arr[100000];

bool isp(long double t) {
    long double left=t;
    int pos=0;
    long double lp;
    bool flag=true;
    for(int i=0;i<n;i++) {
        if (arr[i]-pos>left*(i+1)) {
            lp=pos+left*(i+1);
            flag=false;
            break;
        }
        else {
            left-=((long double)arr[i]-pos)/(i+1);
            pos=arr[i];
        }
    }
    if (flag&&l-arr[n-1]>left*(n+1)) {
        lp=pos+left*(n+1);
    }
    else if (flag) {
        lp=l;
    }
    left=t;
    pos=l;
    long double rp;
    flag=true;
    for(int i=n-1;i>=0;i--) {
        if (pos-arr[i]>left*(n-i)) {
            rp=pos-left*(n-i);
            flag=false;
            break;
        }
        else {
            left-=((long double)pos-arr[i])/(n-i);
            pos=arr[i];
        }
    }
    if (flag&&arr[0]>left*(n+1)) {
        rp=pos-left*(n+1);
    }
    else if (flag) {
        rp=0;
    }
    return lp>=rp;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d",&n,&l);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        long double lo=0;
        long double hi=1e9;
        for(int i=0;i<100;i++) {
            long double mid=(lo+hi)/2;
            if (isp(mid)) {
                hi=mid;
            }
            else {
                lo=mid;
            }
        }
        printf("%.12Lf\n",hi);
    }
}