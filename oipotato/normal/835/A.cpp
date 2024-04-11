#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const string answer[3]={"First","Second","Friendship"};
int main()
{
    int s,v1,v2,t1,t2;scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    t1=t1*2+s*v1;t2=t2*2+s*v2;
    cout<<answer[t1!=t2?(t1>t2):2]<<endl;
    return 0;
}