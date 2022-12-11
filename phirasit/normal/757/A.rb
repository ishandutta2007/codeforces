inp = gets.strip
str = "Bulbasaur"
puts str.chars.map { |c| inp.count(c) / str.count(c) }.min