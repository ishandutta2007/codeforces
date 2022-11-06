work :: Integer -> Integer -> Integer
work 0 a = 0
work a 0 = 0
work a b = div (max a b) (min a b) + work (mod (max a b) (min a b)) (min a b)

main = do
  a <- getLine
  let [c,d]=map (read::String->Integer) (words a)
  print $work c d