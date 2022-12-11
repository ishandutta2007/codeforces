n = gets.strip.to_i
data = gets.split.map(&:to_i)

count = [0] * (data.max + 1)
data.each { |i| count[i] += 1 }

puts ([1] + (2...count.length).map { |i| 
    (i...count.length).step(i).map { |j| 
        count[j] 
    }.reduce(0, :+) 
}).max