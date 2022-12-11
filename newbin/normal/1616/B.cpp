#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 1e5+5;
char s[maxn];
int n;
int main(){
    int T;cin>>T;
    while(T--){
        scanf("%d", &n);
        scanf("%s", s+1);
        int p = -1;
        for(int i = 1; i < n; ++i) {
            if(s[i] < s[i+1]){
                p = i; break;
            }
        }
        if(p == -1){
            if(n == 1) p = 1;
            else {
                if(s[1] == s[2]) p = 1;
                else p = n;
            }
        }else{
            if(s[1] == s[2]) p = 1;
        }
        fors(i,1,p+1) printf("%c", s[i]);
        for(int i = p; i > 0; --i) printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}