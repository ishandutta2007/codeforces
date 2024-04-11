import Data.List
    
main = do
    s <- getLine
    let [x, y] = map (read :: String -> Int) $ words s
    putStrLn $ if or [(x == y), and [x == 2, y == 4], and [x == 4, y == 2]]
                then "="
            else if fromIntegral y * logBase 2 (fromIntegral x) < fromIntegral x * logBase 2 (fromIntegral y)
                then "<"
            else ">"