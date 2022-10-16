#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

typedef long long int llint;

const int N = 1e5+500;

string s;

int sol = 0;
int mod = 1e9+7;
int n,k;


llint fak[N],pov[N],spov[N],dpov[N];

llint pot(int a,int b){
    llint pov = b;
    llint base = a,sol = 1;
    while(pov != 0){
        if(pov&1) sol = (sol*base)%mod;
        base = (base * base)%mod;
        pov/=2;
    }
    return sol;
}

llint inv(llint a){
    return pot(a,mod-2)%mod;
}

llint povrh(int n,int k ){
    return ((fak[n] * inv(fak[k])) % mod) * inv(fak[n-k])%mod;
}

void generiraj(){
    fak[0] = 1;
    for(int i = 1;i<N;i++){
        fak[i] = (i * fak[i-1])%mod;
    }
}

int generiraj2(){
    pov[0] = povrh(n-2,k-1);
    for(int i = 1;i<=n;i++){
        pov[i] = ((povrh(n-i-2,k-1) * pot(10,i))%mod + pov[i-1])%mod;
    }
}


int main(){
    scanf("%d%d",&n,&k);
    cin >> s;
    generiraj();
    generiraj2();
    llint sol = 0;
    for(int i = 0;i<s.size();i++){
        llint s1;
        if(n-i-1 > (n-k)-1){
            s1 = (pov[(n-k)-1] * (s[i]-'0'))%mod;
        }
        else{

            if(n-i-2 < 0) s1 = (povrh(i,k)) *  (s[i]-'0');
            else {s1 = (((pov[n-i-2] + (povrh(i,k)*pot(10,(n-i-1)))%mod)%mod) * (s[i]-'0'))%mod;}
        }
        sol+=s1;
        sol%=mod;
    }
    printf("%d\n",sol);
}
/******
2|3|5|8
0 1 2 3
4 3 2 1
******/