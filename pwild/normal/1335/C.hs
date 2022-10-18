import Control.Monad
import Data.List

solve :: [Int] -> Int
solve xs = max u v
  where
    counts = map length $ group $ sort xs
    mc = maximum counts
    mt = length counts
    u = min mc (mt-1)
    v = min mt (mc-1)

main :: IO ()
main = do
  tc <- readLn
  replicateM_ tc $ do
    getLine
    xs <- map read . words <$> getLine
    print $ solve xs