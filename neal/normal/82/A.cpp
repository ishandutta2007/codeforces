#include <cstdio>
using namespace std;

const char *BIGBANG [5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int N;

int main ()
{
    scanf ("%d", &N); N--;
    int count = 5;

    while (N >= count)
    {
        N -= count;
        count *= 2;
    }

    puts (BIGBANG [N / (count / 5)]);
    return 0;
}