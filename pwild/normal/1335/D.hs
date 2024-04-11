import Control.Monad

mutations :: [(Int,Int)]
mutations = [(0,0),(1,3),(2,6),(3,1),(4,4),(5,7),(6,2),(7,5),(8,8)]

solve :: [String] -> [String]
solve grid = [[cell i j | j <- [0..8]] | i <- [0..8]]
  where 
    cell i j = let old = grid !! i !! j
               in if (i,j) `elem` mutations then inc old else old
    inc x = if x == '9' then '1' else succ x

main :: IO ()
main = do
  tc <- readLn
  replicateM_ tc $ do
    grid <- replicateM 9 getLine
    mapM_ putStrLn $ solve grid