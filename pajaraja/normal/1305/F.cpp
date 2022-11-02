#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
typedef long long int llui;
typedef long double float64;
long long nz[MAXN];
llui mul_mod(llui a, llui b, llui m){
   llui y = (llui)((float64)a*(float64)b/m+(float64)1/2);
   y = y * m;
   llui x = a * b;
   llui r = x - y;
   if ( (llui)r < 0 ){
      r = r + m; y = y - 1;
   }
   return r;
}
llui C,a,b;
llui gcd()
{
   llui c;
   if(a>b)
   {
      c = a; a = b; b = c;
   }
   while(1)
   {
      if(a == 1LL) return 1LL;
      if(a == 0 || a == b) return b;
      c = a; a = b%a;
      b = c;
   }
}
llui f(llui a, llui b)
{
   llui tmp;
   tmp = mul_mod(a,a,b);
   tmp+=C; tmp%=b;
   return tmp;
}
llui pollard(llui n)
{
   	if(!(n&1)) return 2;
   	llui cnt=2;
   	llui iteracoes = 0;
   	C=1;
   	while(true)
	{
      	llui x,y,d;
      	x = y = cnt; d = 1;
      	while(d == 1)
		{
		  	x = f(x,n);
          	y = f(f(y,n),n);
          	llui m = (x>y)?(x-y):(y-x);
          	a = m; b = n; d = gcd();
      	}
      	cnt++;
		if(d != n) return d;
		C=rand();
   	}
	return 1;
}
llui pot(llui a, llui b, llui c)
{
   	if(b == 0) return 1;
   	if(b == 1) return a%c;
   	llui resp = pot(a,b>>1,c);
   	resp = mul_mod(resp,resp,c);
   	if(b&1)
    resp = mul_mod(resp,a,c);
   	return resp;
}
bool isPrime(llui n)
{
   	llui d = n-1;
	llui s = 0;
   	if(n <=3 || n == 5) return true;
   	if(!(n&1)) return false;
   	while(!(d&1)){ s++; d>>=1; }
   	for(llui i = 0;i<32;i++){
    llui a = rand();
    a <<=32;
    a+=rand();      
	a%=(n-3); a+=2;
    llui x = pot(a,d,n);
    if(x == 1 || x == n-1) continue;
    for(llui j = 1;j<= s-1;j++)
	{
        x = mul_mod(x,x,n);
        if(x == 1) return false;
        if(x == n-1)break;
    }
    if(x != n-1) return false;
   }
   return true;
}
map<llui,int> factors;
set<llui> wf; 
void fact(llui n){
    if(!isPrime(n))
    {
    	llui fac = pollard(n);
    	fact(n/fac); fact(fac);
    }
    else
	{
    	wf.insert(n);
		//factors[n]++;
	}
}
int N;
llui check(llui p)
{
	llui rez=0;
	for(int i=0;i<N;i++)
	{
		llui x=nz[i]%p;
		if(nz[i]==x) rez+=p-x;
		else rez+=min(p-x,x);
	}
	return rez;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>N;
	llui sol=N+7;
	for(int i=0;i<N;i++) cin>>nz[i];
	mt19937 rng(time(NULL));
	for(int it=0;it<45;it++)
	{
		int x=rng()%N;
		wf.clear();
		llui b=nz[x];
		if(b!=1) fact(b);
		for(set<llui>::iterator it=wf.begin();it!=wf.end();it++)
		{
			llui xx=*it;
			sol=min(sol,check(xx));
			//cout<<xx<<" "<<sol<<endl;
		}
		wf.clear();
		b++;
		fact(b);
		for(set<llui>::iterator it=wf.begin();it!=wf.end();it++)
		{
			llui xx=*it;
			sol=min(sol,check(xx));
		}
		if(b==2 || b==3) continue;
		wf.clear();
		b-=2;
		fact(b);
		for(set<llui>::iterator it=wf.begin();it!=wf.end();it++)
		{
			llui xx=*it;
			sol=min(sol,check(xx));
		}
	}
	cout<<sol;
}