int d,s;
struct D{int x,y;}q[2500005];int l,r;
int v[500][5005];
int ls[2500005];
int S[5005],t;
int main(){
	__builtin_scanf("%d%d",&d,&s);
	q[l=r=1]=(D){0,0};
	while(l<=r){
		D p=q[l];
		for(int i=p.y?0:1;i<=9;++i) if(p.y+i<=s&&!v[(p.x*10+i)%d][p.y+i]) q[++r]=(D){(p.x*10+i)%d,p.y+i}, v[(p.x*10+i)%d][p.y+i]=r, ls[r]=l;
		++l;
	}
	if(!v[0][s]) return __builtin_puts("-1"),0;
	int now=v[0][s];
	while(q[now].y) S[++t]=q[now].y-q[ls[now]].y, now=ls[now];
	while(t) __builtin_printf("%d",S[t--]);
	return 0;
}