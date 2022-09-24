#include<cstdio>
#include<algorithm>

using namespace std;

int b[16], S, a[16];
bool use[16];
int aaa[]={0,1,2,3,4,8,12,15,5,10,6,7,11,9,13,14};

int rec(int p){
    if(p==16)return 1;
    int t=aaa[p];
    if(p==0 || p==1 || p==2 || p==4 || p==5 || p==8 || p==10){
        for(int i=0; i<16; i++){
            if(!use[i]){
                b[t]=a[i];
                use[i]=1;
                if(rec(p+1))return 1;
                use[i]=0;
            }
        }
    }else{
        int x;
        if(p==3)x=S-b[0]-b[1]-b[2];
        if(p==6)x=S-b[0]-b[4]-b[8];
        if(p==7)x=S-b[0]-b[3]-b[12];
        if(p==9)x=S-b[0]-b[5]-b[15];
        if(p==11)x=S-b[4]-b[5]-b[6];
        if(p==12){
            if(b[3]+b[15]!=b[4]+b[8])return 0;
            x=S-b[3]-b[7]-b[15];
        }
        if(p==13){
            if(b[8]+b[10]+b[11]!=b[3]+b[6]+b[12])return 0;
            x=S-b[8]-b[9]-b[10];
        }
        if(p==14)x=S-b[1]-b[5]-b[9];
        if(p==15){
            if(b[1]+b[13]!=b[6]+b[10] || b[12]+b[13]+b[15]!=b[2]+b[6]+b[10])return 0;
            x=S-b[2]-b[6]-b[10];
        }
        b[t]=x;
        for(int i=0; i<16; i++)if(!use[i] && x==a[i]){
            use[i]=1;
            if(rec(p+1))return 1;
            use[i]=0;
        }
    }
    return 0;
}

int main(){
    int n;
    S=0;

    scanf("%d", &n);
    for(int i=0; i<n*n; i++){
        scanf("%d", a+i);
        S=S+a[i];
    }
    S/=n;

    if(n==3){
        for(int i=0; i<9; i++)
            if(a[i]==S/3){
                swap(a[i], a[8]);
                break;
            }

        sort(a, a+8);
        do{
            bool f=1;
            swap(a[4], a[8]);
            for(int i=0; f && i<3; i++){
                int x=0, y=0;
                for(int j=0; j<3; j++){
                    x+=a[i*3+j];
                    y+=a[j*3+i];
                }
                if(x!=S)f=0;
                if(y!=S)f=0;
            }
            {
                int x=0, y=0;
                for(int i=0; f && i<3; i++){
                    x+=a[i*3+i];
                    y+=a[i*3+2-i];
                }
                if(x!=S)f=0;
                if(y!=S)f=0;
            }

            if(f)break;

            swap(a[4], a[8]);
        }while(next_permutation(a, a+8));
    }
    if(n==4){
        rec(0);
        for(int i=0; i<16; i++)a[i]=b[i];
    }


    printf("%d\n", S);
    for(int j=0; j<n; j++)
        for(int i=0; i<n; i++)
            printf("%d%c", a[j*n+i], i==n-1?'\n':' ');

    return 0;
}