#include<bits/stdc++.h>
using u=uint32_t;u n,a,b,c,d,e=0;std::bitset<int(1e8)>X;
main(){std::cin>>n>>a>>b>>c>>d;auto g=[&](u x){u mul=a*x*x*x+b*x*x+c*x+d;for(u i=n;i;i/=x)e+=i/x*mul;};g(2),g(3);for(u i=5,j=2;i<=n;i+=j,j=6-j){if(!X[i/3]){g(i);if(i<=n/i)for(u k=i*i,l=j;k<=n;k+=i*l,l=6-l)X[k/3]=1;}}std::cout<<e;}