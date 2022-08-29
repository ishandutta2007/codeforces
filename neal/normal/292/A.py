N = int(raw_input())
queue = 0
finish, max_queue = 0, 0
prev_time = 0

for i in xrange(N):
    T, C = map(int, raw_input().split())

    if queue > 0:
        queue = max(queue - (T - prev_time), 0)

    queue += C
    max_queue = max(max_queue, queue)
    finish = max(finish, T + queue)
    prev_time = T

print finish, max_queue