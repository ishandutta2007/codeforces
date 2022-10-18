solve :: Int -> Int
solve n = (n-1) `div` 2

main :: IO ()
main = interact $ unlines . map (show . solve . read) . tail . lines