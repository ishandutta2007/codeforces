#include <bits/stdc++.h>
using namespace std;
struct element{
    int a,b;
}a[200007];	
int n;
bool cmp(element a,element b){
    return a.a<b.a;
}
 
int ck(int dt){
    int ret=0,cnt=0;
	for(int i=2;i<=n;i++){
		if(cnt==1){
			if(a[i].a!=a[1].a+(i-2)*dt) ret=i,cnt++;
		}else if(a[i].a!=a[1].a+(i-1)*dt) ret=i,cnt++;
		
		if(cnt==2) {
			ret=0;
			break;
		}
	}
	if(ret) return a[ret].b;
	for(int i=3;i<=n;i++)
		if(a[i].a!=a[2].a+(i-2)*dt) return 0;
	return a[1].b;
}
 
int main(){
    cin>>n;
    if(n==2||n==3) {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i].a),a[i].b=i;
    sort(a+1,a+1+n,cmp);
    int tp=0;
    if(tp=ck(a[2].a-a[1].a)){
        cout<<tp;
    }else if(tp=ck(a[3].a-a[2].a)){
        cout<<tp;
    }else if(tp=ck(a[3].a-a[1].a)){
        cout<<tp;
    }else cout<<-1;
    return 0;
}