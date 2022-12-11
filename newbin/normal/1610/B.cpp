#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 2e5+5;
int a[maxn]; int n;
void init(){
    scanf("%d", &n);
    fors(i,1,n+1) scanf("%d", &a[i]);
}
bool check(int x){
    int l = 1, r = n;
    while(l <= r){
        if(a[l]==a[r]) {l++; r--; continue;}
        else if(a[l] == x) l++;
        else if(a[r] == x) r--;
        else return false;
    }return true;
}
void sol(){
    int l = 1, r = n;
    while(l <= r){
        if(a[l] == a[r]) {l++;r--; continue;}
        else {
            if(check(a[l]) || check(a[r])){
                puts("YES"); return;
            }else{
                puts("NO"); return;
            }
        }
    }
    puts("YES");
    return;
}
int main(){
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
    return 0;
}