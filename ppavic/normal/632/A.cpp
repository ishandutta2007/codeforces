#include <cstdio>

using namespace std;
char x[20];
int b[45];
long long int n,p;
double cur;

int main(){
    scanf("%d %d",&n,&p);
    for(int i = 0;i<n;i++){
        scanf("%s",&x);
        if(x[0]=='h' && x[1]=='a' && x[2]=='l' && x[3]=='f' && x[4]!='p'){
            b[i] = 1;
        }
        else{
            b[i]=0;

        }
    }
    long long int jabuke = 0;
    long long int price = 0;
    for(int i = n-1;i>=0;i--){
        if(b[i]==1){
            if(i==n-1){
                jabuke = 0.5;
                price = p/2;
            }
            else{
                price+=jabuke*p;
                jabuke*=2;

            }
        }
        else{
            if(i==n-1){
                jabuke = 1;
                price = p/2;
            }
            else{
                price+=jabuke*p+p/2;
                jabuke*=2;
                jabuke+=1;
            }
        }
    }
    printf("%I64d",price);
}