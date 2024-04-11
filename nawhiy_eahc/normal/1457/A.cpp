#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, r, c;
        scanf("%d %d %d %d", &n, &m, &r, &c);
        printf("%d\n", max(n-r, r-1) + max(m-c, c-1));
    }
}