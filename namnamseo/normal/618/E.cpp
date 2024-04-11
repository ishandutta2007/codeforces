#include <cstdio>
#include <cmath>
struct v3{
    double a,b,c;
    v3(){ a=b=c=0; }
    v3(double x,double y,double z){ a=x; b=y; c=z; }
};
struct m3{
    v3 c1, c2, c3;
    m3(){
        c1=v3(1,0,0);
        c2=v3(0,1,0);
        c3=v3(0,0,1);
    }
    m3(v3 a,v3 b,v3 c){
        c1=a; c2=b; c3=c;
    }
    v3 operator*(v3& other){
        return v3(
            c1.a*other.a + c2.a*other.b + c3.a*other.c,
            c1.b*other.a + c2.b*other.b + c3.b*other.c,
            c1.c*other.a + c2.c*other.b + c3.c*other.c
            );
    }
    m3 operator*(m3& other){
        return m3(operator*(other.c1),operator*(other.c2),operator*(other.c3));
    }
};
int n;
m3 lazy[1048576];
m3 id3(v3(1,0,0),v3(0,1,0),v3(0,0,1));
v3 data[300010];
inline void pulldown(int pos){
    if(pos>=524288) return;
    lazy[pos*2  ]=(lazy[pos]*lazy[pos*2  ]);
    lazy[pos*2+1]=(lazy[pos]*lazy[pos*2+1]);
    lazy[pos]=id3;
}
void update(int pos,int myl,int myr,int l,int r,m3& tr){
    pulldown(pos);
    if(myr<l || r<myl) return;
    else if(l<=myl && myr<=r){
        lazy[pos]=(tr*lazy[pos]);
    } else {
        update(pos*2  ,myl,(myl+myr)/2  ,l,r,tr);
        update(pos*2+1,(myl+myr)/2+1,myr,l,r,tr);
    }
}
void update(int l,int r,m3& tr){
    update(1,0,524287,l,r,tr);
}
void getPoint(int pos){
    int p=1, myl=0, myr=524287, mm;
    while(p<524288){
        pulldown(p);
        mm=(myl+myr)/2;
        p<<=1;
        if(pos<=mm) myr=mm;
        else myl=mm+1, ++p;
    }
    data[pos]=lazy[p]*data[pos];
    lazy[p]=id3;
}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<=n;++i){
        data[i]=v3(i,0,1);
    }
    int m;
    scanf("%d",&m);
    int x,y,z;
    for(;m--;){
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            getPoint(y-1);
            getPoint(y);
            v3 delta(data[y].a-data[y-1].a,data[y].b-data[y-1].b,1);
            double size = z/hypot(delta.a,delta.b);
            delta.a *= size; delta.b *= size;
            m3 tf(v3(1,0,0),v3(0,1,0),v3(delta.a,delta.b,1));
            update(y,n,tf);
        } else {
            getPoint(y-1);
            double theta = z*3.14159265358979323846264 / 180;
            m3 par1(v3(1,0,0),v3(0,1,0),v3(-data[y-1].a,-data[y-1].b,1));
            m3 par2(v3(cos(theta),-sin(theta),0),v3(sin(theta),cos(theta),0),v3(0,0,1));
            m3 par3(v3(1,0,0),v3(0,1,0),v3( data[y-1].a, data[y-1].b,1));
            m3 tf=par3*par2*par1;
            update(y,n,tf);
        }
        getPoint(n);
        printf("%.15f %.15f\n",data[n].a,data[n].b);
    }
    return 0;
}