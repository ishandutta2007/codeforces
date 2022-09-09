#include <iostream>
#include <cmath>

using namespace std;

struct room
{
    int x, y, z;
};

struct paper
{
    int x, y, num;
};

int number(room rm, paper pr)
{
    int n = (pr.x / rm.z) * pr.y;
    return (((rm.x + rm.y) * 2 - 1) / n + 1) * pr.num;
}

int M, N;
room r[500];
paper p[500];


int main()
{
    cin >> N;
    int i, j;
    for(i = 0; i < N; ++i)
    {
        cin >> r[i].x >> r[i].y >> r[i].z;
    }
    cin >> M;
    for(i = 0; i < M; ++i)
    {
        cin >> p[i].x >> p[i].y >> p[i].num;
    }
    int ans = 0;
    int m = 0;
    for(i = 0; i < N; ++i)
    {
        m = 2000000000;
        for(j = 0; j < M; ++j)
        {
            if(r[i].z <= p[j].x)
            {
                m = min(m, number(r[i], p[j]));
            }
        }
        ans = ans + m;
    }
    cout << ans;
    return 0;
}