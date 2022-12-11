#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int n;
const int maxn = 2e5 + 50;
char s[maxn], t[maxn];
vector<int> v;
int main()
{
	cin>>n;
	scanf("%s%s", s, t);
	int ab = 0, ba = 0;
	for(int i = 0; i < n; ++i) {
        if(s[i] == t[i]) continue;
        if(s[i] == 'a') ab++, v.push_back(i+1);
	}
	for(int i = 0; i < n; ++i){
        if(s[i] == t[i]) continue;
        if(s[i] =='b') ba++, v.push_back(i+1);
	}
	if((ab+ba)&1){
        cout<<-1<<endl;
	}
	else{
        if(ab%2 == 0){
            cout<<ab/2 + ba/2<<endl;
            for(int i = 0; i < v.size(); i += 2){
                int x = v[i];
                int y = v[i+1];
                printf("%d %d\n", x, y);
            }
        }
        else{
            cout<<ab/2 + ba/2 + 2<<endl;
            int x = v[ab-1];
            printf("%d %d\n", x, x);
            for(int i = 0; i < ab-1; i+=2){
                int x = v[i];
                int y = v[i+1];
                printf("%d %d\n", x, y);
            }
            for(int i = ab-1; i < v.size(); i += 2){
                int x = v[i];
                int y = v[i+1];
                printf("%d %d\n", x, y);
            }
        }
	}
}