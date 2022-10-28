#include<stdio.h>
int a[150000],n,q,p;
struct nod{
    int val;
    bool height;
};
nod s[500001];
nod construct(int l,int r,int node){
    if(l==r){
         s[node].val = a[l];
         s[node].height = 0;
        
         return s[node];//0 for taking or at parent
    }
    int mid=l+r;mid>>=1;
    nod temp1,temp2;
    temp1=construct(l,mid,node*2+1);
    temp2=construct(mid+1,r,node*2+2);
    if(temp1.height==0){
        s[node].val = (temp1.val)|(temp2.val);
        s[node].height=1;
    }
    else{
        s[node].val = (temp1.val)^(temp2.val);
        s[node].height=0;
    }
    return s[node];
}
void update(int l,int r,int node,int index,int value){
    if(l>index||index>r){
        return;
    }
    if(l==r){
        s[node].val=value;
        return ;
    } 
    int mid = l+r;
    mid>>=1;
    update(l,mid,node*2+1,index,value);
    update(mid+1,r,node*2+2,index,value);
    if(index>=l&&index<=r){
        if(s[node*2+1].height==0){
            s[node].val= s[node*2+1].val|s[node*2+2].val;
        }
        else{
            s[node].val= s[node*2+1].val^s[node*2+2].val;
        }
        return;
    }
}
int main(){
    scanf("%d%d",&p,&q);
    n=1<<p;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    construct(0,n-1,0);
    while(q--){
        int index,val;
        scanf("%d%d",&index,&val);
        update(0,n-1,0,index-1,val);
        printf("%d\n",s[0]);
    }
}