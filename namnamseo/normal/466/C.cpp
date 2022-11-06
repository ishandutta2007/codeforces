#include <cstdio>

typedef long long ll;

int  data[500001];
int ltree[500010];
int n;

ll wholesum;

void update(int x){
    while(x<=500001){
        ltree[x]++;
        x+=(x&(-x));
    }
}

int tosum(int to){
    int ret = 0;
    while(to){
        ret+=ltree[to];
        to&=(to-1);
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    int i;
    wholesum=0;
    for(i=0;i<n;++i) scanf("%d",data+i),wholesum+=data[i];
    if(wholesum%3){
        puts("0");
    } else {
        wholesum/=3;
        ll tmp=0;
        for(i=0;i<n-2;++i){
            tmp+=data[i];
            if(tmp == wholesum){
                update(i+1);
            }
        }
        tmp=0;
        ll ans=0;
        for(i=n-1;1<i;--i){
            tmp+=data[i];
            if(tmp==wholesum){
                ans+=tosum(i-1);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}