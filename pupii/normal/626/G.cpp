#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int ticket,A[200010],t[200010],s[200010];
double ins[200010],del[200010];
struct data{double x;int i;};
bool operator==(data a,data b){return a.i==b.i&&fabs(a.x-b.x)<1e-10;}
struct cmp{bool operator()(data a,data b){if(fabs(a.x-b.x)>1e-10)return a.x>b.x;else return a.i<b.i;}};
std::priority_queue<data,std::vector<data>,cmp>qi,di,qd,dd;
void recalc(int x){
	if(!std::isnan(ins[x]))di.push({ins[x],x});
	if(!std::isnan(del[x]))dd.push({del[x],x});
	ins[x]=1.0*t[x]*A[x]/(t[x]+s[x]+1)-1.0*t[x]*A[x]/(t[x]+s[x]);
	del[x]=1.0*t[x]*A[x]/(t[x]+s[x]-1)-1.0*t[x]*A[x]/(t[x]+s[x]);
	if(s[x]>=t[x])ins[x]=NAN;else qi.push({ins[x],x});
	if(!s[x])del[x]=NAN;else qd.push({del[x],x});
}
data ins_top(){
	while(!qi.empty()&&!di.empty()&&qi.top()==di.top())qi.pop(),di.pop();
	if(qi.empty())return{NAN,-1};
	else return qi.top();
}
data del_top(){
	while(!qd.empty()&&!dd.empty()&&qd.top()==dd.top())qd.pop(),dd.pop();
	if(qd.empty())return{NAN,-1};
	else return qd.top();
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,q;n=gi(),ticket=gi(),q=gi();
	double now=0,sum=0;
	for(int i=1;i<=n;++i)A[i]=gi(),sum+=A[i],now+=A[i],ins[i]=del[i]=NAN;
	for(int i=1;i<=n;++i)t[i]=gi(),recalc(i);
	while(ticket){
		data a=ins_top();
		if(a.i==-1)break;
		--ticket;
		now+=a.x,++s[a.i];
		recalc(a.i);
	}
	int o,p;
	while(q--){
		o=gi(),p=gi();
		if(o==1){
			now-=1.0*t[p]*A[p]/(t[p]+s[p]);
			++t[p];
			now+=1.0*t[p]*A[p]/(t[p]+s[p]);
			recalc(p);
		}else{
			now-=1.0*t[p]*A[p]/(t[p]+s[p]);
			--t[p];
			now+=1.0*t[p]*A[p]/(t[p]+s[p]);
			recalc(p);
			if(s[p]>t[p])++ticket,now+=del[p],--s[p],recalc(p);
		}
		data tp=del_top();
		if(~tp.i&&!ticket){
			now+=tp.x,--s[tp.i];
			recalc(tp.i);
			++ticket;
		}
		tp=ins_top();
		if(~tp.i&&ticket){
			now+=tp.x,++s[tp.i];
			recalc(tp.i);
			--ticket;
		}
		printf("%.10lf\n",sum-now);
	}
	return 0;
}