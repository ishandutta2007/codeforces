#include <cstdio>
using namespace std;
int gcd(int a, int b){
    return (b==0)?a:gcd(b, a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}
int main(){
    int n, m, z;
    scanf("%d%d%d", &n, &m, &z);
    printf("%d\n", z/lcm(n, m));
    return 0;
}