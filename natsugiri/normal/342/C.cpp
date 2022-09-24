#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

int R, H;
int main() {
    scanf("%d%d", &R, &H);
    int ans = 0;
    int m = (2*H+R)/(2*R);
    ans = max(ans, m*2);

    if ((m+sqrt(3)/2)*R <=  H+R) ans = max(ans, m*2+1);
    
    if (m>1 && (m-1.5+sqrt(3))*R <= H && (m-1+sqrt(3)*1.5)*R <= H+R)
	ans = max(ans, m*2+2);

    printf("%d\n", ans);
    
    return 0;
}