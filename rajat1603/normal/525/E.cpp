#include<bits/stdc++.h>
using namespace std;
int n,k;
long long s;
long long fact[20];
long long arr[26];
int nby2;
long long arr1[15],arr2[15];
long long answer=0;
void init(){
    fact[0]=1;
    for(int i=1;i<=19;++i){
        fact[i]=fact[i-1]*i;
    }
}
vector<long long> firsthalf[26];
unordered_map<long long,long long> secondhalf[26];
void solve1(int pos,int kleft,long long val){
    if(kleft<0){
        return;
    }
    if(val>s){
        return;
    }
    if(pos==0){
        firsthalf[kleft].push_back(val);
        return;
    }
    solve1(pos-1,kleft,val);
    solve1(pos-1,kleft,val+arr1[pos]);
    if(arr1[pos]<19){
        solve1(pos-1,kleft-1,val+fact[arr1[pos]]);
    }
}
void solve2(int pos,int kleft,long long val){
    if(kleft<0){
        return;
    }
    if(val>s){
        return;
    }
    if(pos==0){
        secondhalf[kleft][val]++;
        return;
    }
    solve2(pos-1,kleft,val);
    solve2(pos-1,kleft,val+arr2[pos]);
    if(arr2[pos]<19){
        solve2(pos-1,kleft-1,val+fact[arr2[pos]]);
    }
}
int main(){
    init();
    scanf("%d %d %lld",&n,&k,&s);
    for(int i=1;i<=n;++i){
        scanf("%lld",arr+i);
    }
    nby2 = n>>1;
    for(int i=1;i<=nby2;++i){
        arr1[i]=arr[i];
    }
    for(int i=nby2+1;i<=n;++i){
        arr2[i-nby2]=arr[i];
    }
    solve1(nby2,k,0LL);
    solve2(n-nby2,k,0LL);
    for(int i=0;i<=k;++i){
        int sz = firsthalf[i].size();
        while(sz--){
            long long cur = firsthalf[i][sz];
            for(int l=k-i;l<=k;++l){
                answer+=secondhalf[l][s-cur];
            }
        }
    }
    printf("%I64d",answer);
}