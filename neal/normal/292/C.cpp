#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int N;
bool occur[10];
vector<string> candidates;

string extract1(int n, int *digits)
{
    string str(2 * n, '0');

    for (int i = 0; i < 2 * n; i++)
        str[i] = i < n ? digits[i] + '0' : digits[2 * n - 1 - i] + '0';

    return str;
}

string extract2(int n, int *digits)
{
    string str(2 * n - 1, '0');

    for (int i = 0; i < 2 * n - 1; i++)
        str[i] = i < n ? digits[i] + '0' : digits[2 * n - 2 - i] + '0';

    return str;
}

void recurse(int n, int *digits)
{
    if (n > 0)
    {
        candidates.push_back(extract1(n, digits));
        candidates.push_back(extract2(n, digits));
    }

    if (n == 6)
        return;

    for (int i = 0; i < 10; i++)
        if (occur[i])
        {
            digits[n] = i;
            recurse(n + 1, digits);
        }
}

bool valid(string str)
{
    bool have[10];
    memset(have, false, sizeof(have));

    for (int i = 0; i < (int) str.length(); i++)
        have[str[i] - '0'] = true;

    for (int i = 0; i < 10; i++)
        if (occur[i] ^ have[i])
            return false;

    return true;
}

bool valid8bit(string str)
{
    if (str.length() == 0 || str.length() > 3)
        return false;

    if (str[0] == '0')
        return str.length() == 1;

    return atoi(str.c_str()) < 256;
}

vector<string> answers;

void generate_combinations(string str)
{
    for (int a = 1; a < (int) str.length(); a++)
        for (int b = a + 1; b < (int) str.length(); b++)
            for (int c = b + 1; c < (int) str.length(); c++)
                if (valid8bit(str.substr(0, a)) && valid8bit(str.substr(a, b - a)) && valid8bit(str.substr(b, c - b)) && valid8bit(str.substr(c)))
                    answers.push_back(str.substr(0, a) + "." + str.substr(a, b - a) + "." + str.substr(b, c - b) + "." + str.substr(c));
}

void generate_palindromes()
{
    int *digits = new int[10];
    recurse(0, digits);
    vector<string> ncandidates;

    for (int i = 0; i < (int) candidates.size(); i++)
        if (valid(candidates[i]))
            ncandidates.push_back(candidates[i]);

    candidates = ncandidates;

    for (int i = 0; i < (int) candidates.size(); i++)
        generate_combinations(candidates[i]);
}

int main()
{
    scanf("%d", &N);

    if (N > 6)
    {
        puts("0");
        return 0;
    }

    memset(occur, false, sizeof(occur));
    
    for (int i = 0; i < N; i++)
    {
        int digit;
        scanf("%d", &digit);
        occur[digit] = true;
    }

    generate_palindromes();
    printf("%d\n", (int) answers.size());

    for (int i = 0; i < (int) answers.size(); i++)
        puts(answers[i].c_str());

    return 0;
}