solve :: [Int] -> String
solve [n,a,b] = take n $ cycle $ take b ['a'..]

main :: IO ()
main = interact $ unlines . map (solve . map read . words) . tail . lines