n, n1, n2 = gets.split.map(&:to_i)
data = gets.split.map(&:to_i)

data.sort! { |x, y| y <=> x }
n1, n2 = [n1,n2].minmax

ans = data[0,n1].reduce(0,:+).to_f / n1.to_f + data[n1,n2].reduce(0,:+).to_f / n2.to_f
p ans