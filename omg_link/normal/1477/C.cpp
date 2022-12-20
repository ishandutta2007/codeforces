#include <stdio.h>
#define MN 5000

int n,head,tail;

struct node{
	int id,x,y;
	int last;
	int next;
}p[MN+5];

struct vec{
	int x,y;
	vec(node a,node b){
		x = b.x-a.x;
		y = b.y-a.y;
	}
	long long operator * (const vec& that)const{
		return 1ll*this->x*that.x+1ll*this->y*that.y;
	}
};

bool check(int s,int t){
	if(p[s].last==-1)
		return true;
	int r = p[s].last;
	vec v1(p[r],p[s]),v2(p[s],p[t]);
	return v1*v2<0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id = i;
	}
	p[1].last = -1;
	p[1].next = -1;
	tail = 1;
	head = 1;
	for(int i=2;i<=n;i++){
		for(int c=tail;;c=p[c].last){
			if(c==-1){
				p[i].next = head;
				p[i].last = -1;
				head = i;
				break;
			}
			if(check(c,i)){
				p[i].next = p[c].next;
				p[i].last = c;
				p[c].next = i;
				if(p[i].next==-1)
					tail = i;
				else
					p[p[i].next].last = i;
				break;
			}
		}
	}
	for(int i=head;~i;i=p[i].next){
		printf("%d ",p[i].id);
	}
}