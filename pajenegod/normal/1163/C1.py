# Testing transfusion's code

# every two pairs of points has a line between them

import math, sys

def round_slightly(x):
    return (x + 2**20) - 2**20

if __name__ == "__main__":

    points = []
    lines = []

    n = int(input())

    for i in range(n):
        (x,y) = map(float, input().split())
        points.append((x,y))

    grad_freqs = {}
    grad_freqs_exact = {}

    for i in range(len(points)):
        for j in range(i+1, len(points)):
            ( (x, y), (a, b) ) =  (points[i], points[j])
            y2_y1 = b - y
            x2_x1 = a - x

            # if the x doesn't change, i.e. straight vertical line
            if x == a:
                gradient = float('Inf')
                # actually the x intercept! just as a means to uniquely identify vertical lines!
                intercept = x
            else:
                gradient = y2_y1 / x2_x1
                intercept = y - gradient * x
            
            
            round_gradient = round_slightly(gradient)
            round_intercept = round_slightly(intercept)
            
            if round_gradient not in grad_freqs:
                if gradient not in grad_freqs_exact:
                    grad_freqs_exact[gradient] = set()
                grad_freqs[round_gradient] = set()
            elif gradient not in grad_freqs_exact:
                print(repr(gradient))
                print(repr(round_gradient))
                

            grad_freqs[round_gradient].add(round_intercept)


    total_lines = 0
    for key in grad_freqs.keys():
        grad_freqs[key] = len(grad_freqs[key])
        total_lines += grad_freqs[key]

    # print(grad_freqs)

    res = 0
    values = grad_freqs.values()
    for idx, item in enumerate(values):
        res += (total_lines - item) * item

    print(res // 2)