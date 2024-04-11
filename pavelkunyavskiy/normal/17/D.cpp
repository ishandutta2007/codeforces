#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

char s[3000000];


int pow(int a,int b){   
    if (b==0)
        return 1;
    if (b%2==0){
        int tmp=pow(a,b/2);
        return tmp*tmp;
    }
    return pow(a,b-1)*a;
}

int pow(int a,int b,int mod){   
    if (b==0)
        return 1;
    if (b%2==0){
        int tmp=pow(a,b/2,mod);
        return (tmp*1ll*tmp)%mod;
    }
    return (pow(a,b-1,mod)*1ll*a)%mod;
}




int phi(int n){
    int result = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

int gcd(int a,int b){
    if (!a)
        return b;
    if (!b)
        return a;
    return gcd(b,a%b);
}

void read(int& a,int& b,int& c,int &f){
    gets(s);
    int kol=0;
    a=b=c=0;
    for (int i=0;s[i]!=0;i++)
        {
            if (kol==2)
                c=c*10+s[i]-'0';
            else if (s[i]==' '){
                kol++;
            }
        }
        

    kol=0;  

    int i=0;
    for (;s[i]!=' ';i++){   
        a=(a*1ll*10+s[i]-'0')%c;
    }
    
    int ans=1;
    
    for (i++;s[i]!=' ';i++);
    
    --i;
    s[i]--;
    
    for (;s[i]=='0'-1;i--)
        {
            s[i]+=10;
            s[i-1]--;
        }
    
    i=0;
    
    for (i++;s[i]!=' ';i++);
    
    for (i++;s[i]!=' ';i++){
        ans=pow(ans,10,c);
        int tmp=pow(a,s[i]-'0',c);
        ans=(ans*1ll*tmp)%c;
    }
    
    ans=(ans*1ll*(a-1+c))%c;

    if (ans==0)
        ans=c;
    
    printf("%d\n",ans);

    return;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int a,b,c,f;
  read(a,b,c,f);
  return 0;
}