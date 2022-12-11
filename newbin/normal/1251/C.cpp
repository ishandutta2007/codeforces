#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 3e5 + 50;
queue<int> q[2];
char s[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        while(q[0].size()) q[0].pop();
        while(q[1].size()) q[1].pop();
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; ++i){
            int x = (s[i]-'0')%2;
            q[x].push(s[i]-'0');
        }
        while(q[0].size() && q[1].size()){
            if(q[0].front() < q[1].front()){
                printf("%d",q[0].front()); q[0].pop();
            }
            else{
                printf("%d",q[1].front()); q[1].pop();
            }
        }
        while(q[0].size()){
            printf("%d",q[0].front()); q[0].pop();
        }
        while(q[1].size()){
            printf("%d",q[1].front()); q[1].pop();
        }printf("\n");
    }
}