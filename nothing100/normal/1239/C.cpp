#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
using namespace std;
int n,p;
LL now,ans[100010];
set<int> s,mq;
queue<int> q;
pair<int,int> t[100010];
int main(){
	scanf("%d%d",&n,&p);
	for (int i=0;i<n;i++){
		scanf("%d",&t[i].fi);
		t[i].se=i;
	}
	sort(t,t+n);
	int tail=0;
	for (int i=0;i<n;i++){
		int tmp;
		if (!s.empty()){
			tmp=*s.begin();
			if (q.empty()||tmp<*mq.begin()){
				s.erase(s.begin());
				q.push(tmp);
				mq.insert(tmp);
			}
		}
		if (q.empty()){
			now=t[tail].fi;
			q.push(t[tail].se);
			mq.insert(t[tail].se);
			tail++;
		}
		tmp=q.front();
		now+=p;
		while (tail<n&&t[tail].fi<=now){
			if (q.empty()||t[tail].se<*mq.begin()){
				q.push(t[tail].se);
				mq.insert(t[tail].se);
			}
			else s.insert(t[tail].se);
			tail++;
		}
		q.pop();
		ans[tmp]=now;
		mq.erase(tmp);
	}
	for (int i=0;i<n;i++) printf("%lld ",ans[i]);
}