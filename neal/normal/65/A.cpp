#include <cstdio>
using namespace std;

const char *RON = "Ron", *HERM = "Hermione";

int A, B, C, D, E, F;

int answer (const char *str)
{
    puts (str);
    return 0;
}

int main ()
{
    scanf ("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

    if (C == 0 && D > 0)
        return answer (RON);

    if (A == 0 && B > 0 && D > 0)
        return answer (RON);

    if (E == 0 && F > 0 && B > 0 && D > 0)
        return answer (RON);

    if (B * D * F > A * C * E)
        answer (RON);
    else
        answer (HERM);

    return 0;
}