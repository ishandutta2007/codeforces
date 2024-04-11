#include <cstdio>

using namespace std;

long long res = 8 * (long long)1e18;
long long a[4];
char op[3];

bool norm(long long a, long long b, char op) {
    if  (op == '+') 
       return a + b >= 0 && (a + b) - b == a; 
    else
       return a == 0 || b == 0 || a * b >= 0 && (a * b) / b == a;
}

long long calc(long long a, long long b, char op) {
    if  (op == '+')
        return a + b;
    else
        return a * b;
}

void go(int i) {
    if  (i == 3) {
       for (int j = 0; j < 4; j++)
           if  (a[j] < res && a[j] >= 0) res = a[j];
       return; 
    }
    
    for (int j = 0; j < 4; j++)
        for (int k = j + 1; k < 4; k++)
            if  (norm(a[j], a[k], op[i]) && a[j] != -1LL && a[k] != -1LL) {
               long long J = a[j];
               long long K = a[k];
               a[j] = calc(a[j], a[k], op[i]); a[k] = -1LL;
               go(i + 1);
               a[j] = J;
               a[k] = K;
            }
}

int main()
{
   for (int i = 0; i < 4; i++)
       scanf("%I64d", &a[i]); scanf("\n");
   
   scanf("%c %c %c\n", &op[0], &op[1], &op[2]);
   
   go(0);
   
   printf("%I64d\n", res);
   return 0;
}