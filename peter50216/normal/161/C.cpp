#include<stdio.h>
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int r4(int s1,int s2,int c){
    if(s1==0||s2==0)return 0;
    if(s1>=c&&2*c-s2<=c){
        int r=s1-(2*c-s2)+1;
        r=max(r,c-1);
        return r;
    }
    if(s1>=c)s1=c-1;
    if(s2>=c)s2=c-1;
    return r4(s1,s2,c/2);
}
inline int r3(int s1,int s2){
    return min(s1,s2);
}
inline int r2(int x1,int y1,int s,int c){
    if(s==0)return 0;
    if(x1<=c&&c<=y1){
        if(s>=c){
            int r=min(s,y1)-max(1,x1)+1;
            int a1=max(y1-c,c-x1);
            r=max(r,r3(a1,c-1));
            return r;
        }else{
            int r=r4(s,c-x1,c/2);
            r=max(r,r3(s,y1-c));
            return r;
        }
    }
    if(s>=c)s=c-1;
    if(x1>c){
        x1-=c;y1-=c;
    }
    return r2(x1,y1,s,c/2);
}
inline int run(int x1,int y1,int x2,int y2,int c){
    if(x1<=c&&c<=y1){
        if(x2<=c&&c<=y2){
            int r=min(y2,y1)-max(x2,x1)+1;
            r=max(r,r3(y1-c,y2-c));
            r=max(r,r3(c-x1,c-x2));
            r=max(r,r4(y1-c,c-x2,c/2));
            r=max(r,r4(c-x1,y2-c,c/2));
            return r;
        }else{
            if(x2>c){
                x2-=c;y2-=c;
            }
            int r=r2(x2,y2,y1-c,c/2);
            r=max(r,r2(c-y2,c-x2,c-x1,c/2));
            return r;
        }
    }else if(x2<=c&&c<=y2){
        if(x1>c){
            x1-=c;y1-=c;
        }
        int r=r2(x1,y1,y2-c,c/2);
        r=max(r,r2(c-y1,c-x1,c-x2,c/2));
        return r;
    }
    if(x1>c){
        x1-=c;y1-=c;
    }
    if(x2>c){
        x2-=c;y2-=c;
    }
    return run(x1,y1,x2,y2,c/2);
}
int main(){
    int l1,r1,l2,r2;
    scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    printf("%d\n",run(l1,r1,l2,r2,536870912));

}