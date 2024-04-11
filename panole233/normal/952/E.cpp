#include<bits/stdc++.h>
char s[9],S[20];int n,c,C;int main(){std::cin>>n;for(;c+C<n;)std::cin>>S>>s,(s[1]<99?c:C)++;if(c!=C)C=(c<C?c=C:c)-1;std::cout<<floor(sqrt(C+c-1)+1.01);}