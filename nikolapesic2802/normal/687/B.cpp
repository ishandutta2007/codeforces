#include<algorithm>
long long k,o=1,c;main(){for(scanf("%*d%d",&k);~scanf("%i",&c);o=o/std::__gcd(c,o)*c%k);puts(o?"No":"Yes");}