#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=100003;
char s[maxn];
struct data{
	   int id,val;
	   bool operator < (const data &o)const{
	   		return val>o.val;
	}
};
int main()
{
 	priority_queue<data> que;
 	scanf("%s",&s);
 	ll sum=0;
 	int j=0;
 	for(int i=0;s[i];i++)
 	{
	 		if(s[i]=='(')j++;
	 		if(s[i]==')')j--;
	 		if(s[i]=='?'){
						  int a,b;
						  scanf("%d%d",&a,&b);
						  sum+=b;
						  data tmp;
						  tmp.id=i;
						  tmp.val=a-b;
						  que.push(tmp);
						  s[i]=')';
						  j--;
			}
			while(j<0){
					   if(que.size()){
					   				  sum+=que.top().val,s[que.top().id]='(';
										 que.pop();
						}
					   else break;
					   j+=2;
			}
			if(j<0){printf("-1\n");return 0;}
	}
	if(j){printf("-1\n");return 0;}
	printf("%I64d\n",sum);
	for(int i=0;s[i];i++)printf("%c",s[i]);
	return 0;
}