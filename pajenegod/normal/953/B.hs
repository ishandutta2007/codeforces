import Data.List

solve :: Int -> [Int] -> Int
solve a b =
        (div (maxi - mini) g) - (a-1)
    where
        maxi = maximum b
        mini = minimum b
        l = map (\x -> x-mini) b
        g = foldr gcd (head l) l

main :: IO ()
main = do
  a <- readLn :: IO Int
  ln <- getLine
  let b = map read $ words ln
  print $ solve a b