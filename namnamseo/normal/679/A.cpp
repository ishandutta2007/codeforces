#include <cstdio>

bool isprime(int x){
    for(int i=2;i*i<=x;++i){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

bool ask(int x){
    printf("%d\n",x); fflush(stdout);
    char buf[5];
    scanf("%s",buf);
    return buf[0]=='y';
}

int main()
{
        bool isPrime;
        for(int i=2;i<=10;++i){
            if(!isprime(i)) continue;
            if(ask(i)){
                for(int j=i+1;i*j<=100;++j){
                    if(!isprime(j)) continue;
                    if(ask(j)){
                        isPrime = false; goto ending;
                    }
                }
                if(ask(i*i)){
                    isPrime = false; goto ending;
                }
                isPrime = true; goto ending;
            }
        }
        isPrime = true; goto ending;
ending:
        puts(isPrime?"prime":"composite");
    return 0;
}