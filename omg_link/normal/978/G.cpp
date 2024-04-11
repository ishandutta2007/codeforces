#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#define MN 100
int n,m,a[MN+5],qn=0;
bool u[MN+5];
struct exam{int s,d,c,i;}e[MN+5],*q[MN+5];
bool cmp(exam a,exam b){return a.s<b.s;}
void ans(int x){
	printf("%d",x);
	exit(0);
}
void push(exam *x){
	q[++qn]=x;
	if(u[x->d])ans(-1);
	else u[x->d]=true;
	for(int i=qn;i>=2;i--)
		if(q[i-1]->d>q[i]->d)
			std::swap(q[i-1],q[i]);
		else break;
}
void pop(){
	--qn;
	for(int i=1;i<=qn;i++)
		q[i]=q[i+1];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].s,&e[i].d,&e[i].c);
		e[i].i=i;
	}
	std::sort(e+1,e+1+m,cmp);
	for(int i=1,ei=0;i<=n;i++){
		while(e[ei+1].s==i)push(&e[++ei]);
		if(u[i]){a[i]=m+1;continue;}
		if(qn==0){a[i]=0;continue;}
		if(i>=q[1]->d)ans(-1);
		q[1]->c--; a[i]=q[1]->i;
		if(q[1]->c==0)pop();
	}
	if(qn!=0)ans(-1);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}