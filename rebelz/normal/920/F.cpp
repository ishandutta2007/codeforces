#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef long long ll;
ll d[1000005];

void getprime(int n){
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			d[j]++;
}

int n,m;

struct node{
    int left,right;
    ll val;
    bool flag;
}t[2000005];

int readint(){
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x;
}

void buildtree(int id,int l,int r){
    t[id].left=l,t[id].right=r;
    if(l==r){
        t[id].val=readint();
        if(t[id].val<=2)
            t[id].flag=true;
        return;
    }
    int mid=(l+r)/2;
    buildtree(id<<1,l,mid);
    buildtree(id<<1|1,mid+1,r);
    t[id].val=t[id<<1].val+t[id<<1|1].val;
    t[id].flag=t[id<<1].flag&t[id<<1|1].flag;
}

void change(int id,int l,int r){
    if(t[id].flag)
        return;
    if(t[id].left==l&&t[id].right==r&&l==r){
        t[id].val=d[t[id].val];
        if(t[id].val<=2)
            t[id].flag=true;
        return;
    }
    if(t[id<<1].right>=r)
        change(id<<1,l,r);
    else if(t[id<<1|1].left<=l)
        change(id<<1|1,l,r);
    else
        change(id<<1,l,t[id<<1].right),change(id<<1|1,t[id<<1|1].left,r);
    t[id].val=t[id<<1].val+t[id<<1|1].val;
    t[id].flag=t[id<<1].flag&t[id<<1|1].flag;
}

ll query(int id,int l,int r){
    if(t[id].left==l&&t[id].right==r)
        return t[id].val;
    if(t[id<<1].right>=r)
        return query(id<<1,l,r);
    else if(t[id<<1|1].left<=l)
        return query(id<<1|1,l,r);
    else
        return query(id<<1,l,t[id<<1].right)+query(id<<1|1,t[id<<1|1].left,r);
}

int main(){
    getprime(1000000);
    n=readint(); m=readint();
    buildtree(1,1,n);
    int opt,x,y;
    for(int i=1;i<=m;i++){
        opt=readint(); x=readint(); y=readint();
        if(opt==1)
            change(1,x,y);
        else
        	printf("%lld\n",query(1,x,y));
    }
    return 0;
}