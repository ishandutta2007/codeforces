
import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Array

readInt :: IO Integer
readInt = read <$> getLine
readIntList :: IO [Integer]
readIntList = fmap read . words <$> getLine
readIntArray :: Integer -> IO (Array Integer Integer)
readIntArray n = listArray (0, n-1) <$> readIntList
readSortedIntArray :: Integer -> IO (Array Integer Integer)
readSortedIntArray n = listArray (0, n-1) . sort <$> readIntList

main :: IO ()
main = do
  [a, b, c, d] <- readIntList
  let (x, y) = if a*d <= b*c then (b*c-a*d, b*c) else (a*d-b*c, a*d)
  let g = gcd x y
  let (x', y') = (x `div` g, y `div` g)
  putStrLn $ show x' ++ "/" ++ show y'