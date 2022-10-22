#include <bits/stdc++.h>
using namespace std;

int arr[300001];
typedef pair<int,int> P;
long long righ[30];
long long inv[30];

void solve(int bit,vector<int> v) {
    if (bit<0) {
        return;
    }
    if (v.size()<=1) {
        return;
    }
    int zero=0;
    int one=0;
    int prev=-1;
    vector<int> z;
    vector<int> o;
    for(int i=0;i<v.size();i++) {
        if (i+1==v.size()||(((v[i]>>bit)&1)!=((v[i+1]>>bit)&1))) {
            if (v[i]&(1<<bit)) {
                inv[bit]+=1LL*(i-prev)*zero;
                one+=i-prev;
            }
            else {
                righ[bit]+=1LL*(i-prev)*one;
                zero+=i-prev;
            }
            prev=i;
        }
        if (v[i]&(1<<bit)) {
            o.push_back(v[i]);
        }
        else {
            z.push_back(v[i]);
        }
    }
    //printf("%d %d\n",zero,one);
    solve(bit-1,z);
    solve(bit-1,o);
}

int main(void) {
    int tc=1;
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        //n=300000;
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            //arr[i]=rand()%1000000001;
        }
        //printf("\n");
        long long x=0;
        long long ret=0;
        vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(arr[i]);
        }
        solve(29,v);
        for(int i=0;i<30;i++) {
            if (righ[i]>inv[i]) {
                x^=(1<<i);
            }
            ret+=min(righ[i],inv[i]);
        }
        printf("%lld %lld\n",ret,x);
    }
}